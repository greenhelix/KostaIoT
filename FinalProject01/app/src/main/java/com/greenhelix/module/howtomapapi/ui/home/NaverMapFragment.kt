package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
import com.greenhelix.module.howtomapapi.R
import android.graphics.Color
import android.graphics.PointF
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ProgressBar
import android.widget.TextView
import androidx.activity.result.contract.ActivityResultContracts
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import com.greenhelix.module.howtomapapi.databinding.FragmentNaverMapBinding
import com.naver.maps.geometry.LatLng
import com.naver.maps.map.*
import com.naver.maps.map.overlay.InfoWindow
import com.naver.maps.map.overlay.Marker
import com.naver.maps.map.util.FusedLocationSource
import com.naver.maps.map.util.MarkerIcons


class NaverMapFragment : Fragment(), OnMapReadyCallback{

    private lateinit var mapViewModel: MapViewModel
    private var _binding: FragmentNaverMapBinding? = null
    private val binding get() = _binding!!

    private lateinit var locationSource: FusedLocationSource

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.d("Ik", "Fragment onCreate")

        // 사용자 위치 권한 허용 여부 확인
        Log.d("Ik", "위치정보 허용 권한 묻기")
        permissionRequest.launch(arrayOf(
            android.Manifest.permission.ACCESS_FINE_LOCATION,
            android.Manifest.permission.ACCESS_COARSE_LOCATION))
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View {
        Log.d("Ik", "Fragment onCreateView")
        mapViewModel =
            ViewModelProvider(
                this,
                ViewModelProvider.NewInstanceFactory()
            )[MapViewModel::class.java]

        _binding = FragmentNaverMapBinding.inflate(inflater, container, false)
        val root: View = binding.root

        locationSource = FusedLocationSource(this, 1000 )

        val mapFragment = childFragmentManager.findFragmentById(R.id.naver_map_view) as MapFragment?
            ?: MapFragment.newInstance().also {
                childFragmentManager.beginTransaction().add(R.id.naver_map_view, it).commit()
            }
        mapFragment.getMapAsync(this)

        return root
    }

    private val permissionRequest = registerForActivityResult(
        ActivityResultContracts.RequestMultiplePermissions()){ permission ->
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

    private class InfoWindowAdapter(private val context: Context) : InfoWindow.ViewAdapter(){
        private var rootView : View? = null
        override fun getView(info: InfoWindow): View {
            val view = rootView ?: View.inflate(context, R.layout.window_info_custom, null).also { rootView = it }
            val progress = view.findViewById<ProgressBar>(R.id.show_data_progress)

            val text1 = view.findViewById<TextView>(R.id.card_tv_store_name)
            val text2 = view.findViewById<TextView>(R.id.card_tv_store_describe)
            val marker = info.marker

            if(marker != null){

                progress.progress = 40

                text1.text = "김익환 카페"
                text2.text = "여기는 가게 설명 샘플입니다. \n카페입니다. 여기는"

            }else{
                progress.progress = 0
                text1.text = "no 카페"
                text2.text = "여기는 no sample입니다. \n where am i?"

            }
            return view
        }
    }

    override fun onMapReady(naverMap: NaverMap) {
        Log.d("ik", "mapOptions")



        val infoWindow = InfoWindow().apply {
            anchor = PointF(0f, 1f)
            offsetX = resources.getDimensionPixelSize(R.dimen.custom_info_window_offset_x)
            offsetY = resources.getDimensionPixelSize(R.dimen.custom_info_window_offset_y)
            setOnClickListener {
                close()
                true
            }
        }
        infoWindow.anchor = PointF(1f, 1f)

        naverMap.locationSource = locationSource

        naverMap.cameraPosition = CameraPosition(NaverMap.DEFAULT_CAMERA_POSITION.target, NaverMap.DEFAULT_CAMERA_POSITION.zoom, 37.0, 45.0)

        naverMap.uiSettings.isCompassEnabled = true

        naverMap.uiSettings.isLocationButtonEnabled = true

        Marker().apply {
            position = LatLng(37.5670135, 126.9783740)
            map = naverMap
            setOnClickListener {
                infoWindow.open(this)
                infoWindow.adapter = InfoWindowAdapter(requireContext())
                true
            }
        }

        Marker().apply {
            position = LatLng(37.57000, 126.97618)
            icon = MarkerIcons.BLACK
            angle = 315f
            map = naverMap
            setOnClickListener {
                infoWindow.open(this)
                infoWindow.adapter = InfoWindowAdapter(requireContext())
                true
            }

        }

        Marker().apply {
            position = LatLng(37.56500, 126.9783881)
            icon = MarkerIcons.BLACK
            iconTintColor = Color.RED
            alpha = 0.5f
            map = naverMap
            setOnClickListener {
                infoWindow.open(this)
                infoWindow.adapter = InfoWindowAdapter(requireContext())
                true
            }
        }

        naverMap.setOnMapClickListener { _, cord ->
            infoWindow.position = cord
            infoWindow.close()
        }


    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}
