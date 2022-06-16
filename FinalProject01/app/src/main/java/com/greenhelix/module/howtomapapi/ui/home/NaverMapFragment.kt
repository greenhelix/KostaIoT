package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.activity.result.contract.ActivityResultContracts
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.lifecycleScope
import com.greenhelix.module.howtomapapi.R
import com.greenhelix.module.howtomapapi.databinding.FragmentNaverMapBinding
import com.greenhelix.module.howtomapapi.databinding.WindowInfoCustomBinding
import com.greenhelix.module.howtomapapi.model.Mark
import com.naver.maps.geometry.LatLng
import com.naver.maps.map.*
import com.naver.maps.map.overlay.InfoWindow
import com.naver.maps.map.overlay.Marker
import com.naver.maps.map.overlay.OverlayImage
import com.naver.maps.map.util.FusedLocationSource
import com.naver.maps.map.util.MarkerIcons
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.flow.collect
import kotlinx.coroutines.launch


class NaverMapFragment : Fragment(), OnMapReadyCallback{

    private lateinit var mapViewModel: MapViewModel
    private var _binding: FragmentNaverMapBinding? = null
    private val binding get() = _binding!!
    private var contain : ViewGroup? = null
    private lateinit var locationSource: FusedLocationSource
    private val permissionRequest = registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()){ permission ->

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            when {
                permission.getOrDefault(android.Manifest.permission.ACCESS_FINE_LOCATION, false) ->{
                    Log.d("Ik", "위치정보 허용")
                }
                permission.getOrDefault(android.Manifest.permission.ACCESS_COARSE_LOCATION, false) -> {
                    Log.d("Ik", "위치정보 허용")
                } else -> {
                Log.d("Ik", "위치정보 허용 거부")
            }
            }
        }
    }
    private var vmMarkers : MutableList<Mark>? = null
    private var vmMarkerInfos : MutableList<Mark>? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // 사용자 위치 권한 허용 여부 확인
        Log.d("Ik", "위치정보 허용 권한 묻기")
        permissionRequest.launch(arrayOf(
            android.Manifest.permission.ACCESS_FINE_LOCATION,
            android.Manifest.permission.ACCESS_COARSE_LOCATION))
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View {
        mapViewModel= ViewModelProvider(requireActivity())[MapViewModel::class.java]
        _binding = FragmentNaverMapBinding.inflate(inflater, container, false)
        contain = container
        locationSource = FusedLocationSource(this, 1000 )

        // 통신 테스트
        mapViewModel.conMQTT(requireContext())

        val mapFragment = childFragmentManager.findFragmentById(R.id.naver_map_view) as MapFragment?
            ?: MapFragment.newInstance().also { childFragmentManager.beginTransaction().add(R.id.naver_map_view, it).commit() }

        mapFragment.getMapAsync(this)

        binding.btnNaverMapRefresh.setOnClickListener {

            mapFragment.getMapAsync(this)
        }
        return binding.root
    }

    // 네이버 지도 정보창 커스텀 뷰 적용하기 위한 View adapter 설정 내부 클래스
    private inner class InfoWindowAdapter(private val context: Context, private  val id : String?) : InfoWindow.ViewAdapter(){

        var adapterBinding : WindowInfoCustomBinding? = null
        private val cardBinding get() = adapterBinding

        override fun getView(info: InfoWindow): View {

            adapterBinding = WindowInfoCustomBinding.inflate(LayoutInflater.from(context), contain, false)
            val progress = cardBinding?.showDataProgress
            val text1 = cardBinding?.cardTvStoreName
            val text2 = cardBinding?.cardTvStoreDescribe
            val title = cardBinding?.cardTvTitle
            val marker = info.marker

//            //뷰바인딩 적용 안했을 때 뷰를 가져오는 방법
//            val view = View.inflate(context, R.layout.window_info_custom, null)
//            val view = rootView ?: View.inflate(context, R.layout.window_info_custom, null).also { rootView = it }
//            val text1 = view.findViewById<TextView>(R.id.card_tv_store_name)

            if(marker != null){
//                progress!!.progress = 40
                mapViewModel.stName.observe(viewLifecycleOwner) {
                    text1!!.text = it
                }
                mapViewModel.stDesc.observe(viewLifecycleOwner) {
                    text2!!.text = it
                }
                mapViewModel.stPercent.observe(viewLifecycleOwner){
                    progress!!.progress = it
                    if (it > 50){
                        title!!.text = "남자가 더 많아요.."
                    }else{
                        title!!.text = "여자가 더 많아요!!"
                    }
                }

            }
            else
            {
                progress!!.progress = 0
                text1!!.text = getString(R.string.except_noDataAlert)
                text2!!.text = getString(R.string.except_noDescribeAlert)
            }

            return cardBinding!!.root
        }
    }

    override fun onResume() {
        Log.d("IK", "onResume")
        super.onResume()
    }

    override fun onPause() {
        Log.d("IK", "onPause")
        super.onPause()
    }

    override fun onStop() {
        Log.d("IK", "onStop")
        super.onStop()
    }

    override fun onMapReady(naverMap: NaverMap) {

        Log.d("IK", "onMapReady")
        val locate = locationSource
        val infoWindow = InfoWindow().apply {
            setOnClickListener {
                close()
                true
            }
        }

        mapViewModel.parsePosData()

        naverMap.apply {
            locationSource = locate
            cameraPosition = CameraPosition(
                NaverMap.DEFAULT_CAMERA_POSITION.target,
                NaverMap.DEFAULT_CAMERA_POSITION.zoom,
                37.0,
                45.0
            )
            uiSettings.isCompassEnabled = true
            uiSettings.isLocationButtonEnabled = true
            buildingHeight = 1.0f
            setOnMapClickListener { _, latLng ->
                infoWindow.position = latLng
                infoWindow.close()
            }
            moveCamera(CameraUpdate.scrollTo(LatLng(37.5139, 126.8926)))  // 문래역 쪽 카메라 위치
        }

        lifecycleScope.launch{
            mapViewModel.makeMarks().collect{
                vmMarkers = it
            }
        }

        lifecycleScope.launch{
            mapViewModel
        }

        Log.d("IK" , "NaverMapFragment::connectData::observe::${vmMarkers}")

        if(vmMarkers!=null){
            var i = 0
            while(i<vmMarkers!!.size){
                Marker().apply {
                    Log.d("IK" , "NaverMapFragment::connectData::observe::${vmMarkers!![i]}")
                    val coordinate= vmMarkers!![i].pos.split(",")
                    position = LatLng(coordinate[0].toDouble(), coordinate[1].toDouble())
                    icon = MarkerIcons.BLUE
                    map = naverMap
                    setOnClickListener {
                        infoWindow.open(this)
                        infoWindow.adapter = InfoWindowAdapter(requireContext(), vmMarkerInfos!![i].marketID)
                        true
                    }
                }
                i++
            }
        }
    }

    private fun getMarkerInfo(mark : Marker, info: InfoWindow){
        mark.apply{
            setOnClickListener {
                info.open(this)
                info.adapter = InfoWindowAdapter(requireContext(), "1")
                true
            }
        }
    }

    override fun onDestroyView() {
        super.onDestroyView()

        // fragment class 의 뷰 바인딩 해제 시키기
        _binding = null

        // inner class 부분에서 뷰 바인딩 해제 시키기 위한 방법
        //InfoWindowAdapter(requireContext(), null).adapterBinding = null

        //mapViewModel.disconnectMQTT()
    }
}
