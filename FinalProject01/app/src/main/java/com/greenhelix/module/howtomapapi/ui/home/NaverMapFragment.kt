package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
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
import com.naver.maps.map.util.FusedLocationSource
import com.naver.maps.map.util.MarkerIcons
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
    private class InfoWindowAdapter(private val context: Context, val mark: Mark) : InfoWindow.ViewAdapter(){
        var _infoCard : WindowInfoCustomBinding? = null
        private val card get() = _infoCard!!
        override fun getView(info: InfoWindow): View {
            _infoCard = WindowInfoCustomBinding.inflate(LayoutInflater.from(context))

            val marker = info.marker
            if(marker != null){
                if(mark.ratio < 50){
                    card.cardTvTitle.text = "여자가 더 많아요!"
                }else{
                    card.cardTvTitle.text = "남자가 더 많아요..."
                }
                card.cardTvStoreName.text  = mark.marketName
                card.cardTvStoreDescribe.text = mark.about
                card.showDataProgress.progress = mark.ratio
            }else{
                if(mark.ratio < 50){
                    card.cardTvTitle.text = "없어요"
                }else{
                    card.cardTvTitle.text = "없어요"
                }
                card.cardTvStoreName.text  = "marketName"
                card.cardTvStoreDescribe.text = "about"
                card.showDataProgress.progress = 100
            }
            return card.root
        }
    }

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
    override fun onDestroyView() {
        super.onDestroyView()

        // fragment class 의 뷰 바인딩 해제 시키기
        _binding = null

    }
    override fun onMapReady(naverMap: NaverMap) {

        Log.d("IK", "onMapReady")
        val locate = locationSource
        mapViewModel.parseData()

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
            moveCamera(CameraUpdate.scrollTo(LatLng(37.5139, 126.8926)))  // 문래역 쪽 카메라 위치
        }

        lifecycleScope.launch{

            mapViewModel.makeMarks().collect{ markers ->

                Log.d("IK" , "NaverMapFragment::connectData::observe::${markers}")
                var i = 0
                while(i < markers.size)
                {
                    val infoWindow = InfoWindow().apply {
                        adapter = InfoWindowAdapter(requireContext(), markers[i])
                        setOnClickListener {
                            close()
                            true
                        }
                    }
                    val coordinate= markers[i].pos.split(",")
                    val position = LatLng(coordinate[0].toDouble(), coordinate[1].toDouble())

                    Marker(position).apply {
                        Log.d("IK" , "NaverMapFragment::connectData::\nvmMarkers[$i]::${markers[i]}")
                        icon = MarkerIcons.GREEN
                        map = naverMap
                        setOnClickListener {
                            infoWindow.open(this)
                            true
                        }
                    }
                    i++
                }
            }
        }
    }
}