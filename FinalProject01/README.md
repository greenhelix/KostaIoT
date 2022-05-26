# Naver Map API 환경설정

## 1. Gradle 처리

### 1️⃣ project : gradle을 확인한다.<br>

> 가이드의 사항에는 allprojects 부분에 해당 문구를 추가하라고 한다.

build.gradle : project

```Gradle
//...
allprojects {
    repositories {
        google()
        mavenCentral()
        jcenter()
        maven {
            url 'https://naver.jfrog.io/artifactory/maven/'
        }
    }
}
//...
```

✅ Sync Now Click !!⚒️

<br>

> 그러나, Sync 가 안되는 경우도 있다. <br>혹은 allprojects 자체가 안된다고 뭐라 뭐라 한다. <br> 이러한 경우 settings.gradle 파일로 이동하여 해당 문구를 추가해줘야 한다.

settings.gradle

```Gradle
pluginManagement {
    repositories {
        gradlePluginPortal()
        google()
        mavenCentral()
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google()
        mavenCentral()
        jcenter() // Warning: this repository is going to shut down soon
        maven {
            url 'https://naver.jfrog.io/artifactory/maven/'
        }
    }
}
rootProject.name = "HowToMapAPI"
include ':app'
```

### 2️⃣ app : gradle을 확인한다. <br>

> 네이버 지도 의존성을 추가해준다. 이게 잘 되야 사용할 수 있다.

build.gradle : app

```Gradle
//...

dependencies {
    implementation 'com.naver.maps:map-sdk:3.14.0'
    //...
}

//...
```

✅ Sync Now Click !!⚒️

<br>

### 3️⃣ 위의 sync 가 안된다면? <br>

> 큰일 난거다. (ㅈ됐다.)<br>
> 천천히 여러 작업을 해줘본다. <br>
> ❓ gradle.properties 를 수정해본다.
>```properties
>android.useAndroidX=true
>android.enableJetifier=true
>```
> 위의 코드가 입력되어 있는지 확인.

✅ Sync Now Click !!⚒️

<br>

> 안된다? 마지막이다.<br>
> Android Studio 를 껐다 켜본다. <br>
> Refactor -> Migrate AndroidX 를 해본다. (백업? 그딴건 개나줘라)

✅ Sync Now Click !!⚒️

## 대충 이정도면 웬만하면 정상적으로 가져온다.

> 위의 방법에도 안된다? 그냥 새로 다시 해보자
>
> 새롭게 프로젝트를 시작해보자 <br>
> 프로젝트 생성시 Use legacy android.support libaries 을 활성화한 뒤새로 만들어본다. <br>
> 이제 옛날 android 시절 빌드가 되어있다. <br>
> 이제 다시 위의 방법 1번부터 다시 해본다.

<br>

## 2. Naver Map API 사용 방법

> [네이버 공식 문서](https://navermaps.github.io/android-map-sdk/guide-ko/1.html)<br>
위의 내용을 다 읽어보면 좋지만, 짧고 간단하게 사용하는 방법이 필요하다.
> 생각이 날 때마다, 아니면 사용할 때마다 필요한 부분을 구분해서 계속 추가해나가면 될 듯 하다.

### 💡 Fragment + ViewModel + Data Binding 구조에서 지도 띄우고 뭐할지 생각해보고싶다면?

> 정말 간편하게 일단 지도 띄어두고 시작하고 싶은 경우가 있다. <br>
> 그러한 경우라고 생각했을 때 막힘 없이 바로 하는 방법
> 1. 먼저, 원하는 Fragment를 선택한다. 기본틀이기 때문에 어떤식으로는 <br>
>    DataBinding이 되어있고, ViewModel도 만들어져서 선언되어있을 것이다.
> ```xml
>     <fragment
>         android:id="@+id/map_naver_frag"
>         android:layout_width="match_parent"
>         android:layout_height="match_parent"
>         android:name="com.naver.maps.map.MapFragment" />
> ```
>
> 위와 같이 xml부분에서 name 부분에 "com.naver.maps.map.MapFragment"를  선언해준다. <br>
>
> 2. 위의 해당되는 Fragment의 kotlin 부분에서 binding을 무시하고,
>    아래의 코드를 추가해준다.
>
> ```kotlin
> override fun onCreateView( inflater: LayoutInflater, container: ViewGroup?, > savedInstanceState: Bundle?): View {
>         //...
>     val mapFragment = childFragmentManager.findFragmentById(R.idmap_naver_frag) > as MapFragment?
>     ?: MapFragment.newInstance(
>             NaverMapOptions().camera(
>                 CameraPosition(
>                     NaverMap.DEFAULT_CAMERA_POSITION.target,
>                     NaverMap.DEFAULT_CAMERA_POSITION.zoom,
>                     30.0,
>                     45.0
>                 )
>             )
>         ).also {
>             childFragmentManager.beginTransaction().add(R.id.map_naver_frag,  this).commit()
>         }
>     mapFragment.getMapAsync(this)
>
>     return root
> }
> ```
>
> 위와 같이 코드를 작성해준다면, <br>
> 데이터 바인딩과는 상관없이 화면상에 지도객체가 생성이 되어 화면에 띄어진다.

### 💡 지도 상단이 여백이 보이는 상태라면?

> xml 상에서 뭔가가 이상한 것이다. <br>
> fragment를 통제하는 Activity의 xml 부분의 코드를 본다.
> ```xml
> <?xml version="1.0" encoding="utf-8"?>
> <androidx.constraintlayout.widget.ConstraintLayout
>     xmlns:android="http://schemas.android.com/apk/res/android"
>     xmlns:app="http://schemas.android.com/apk/res-auto"
>     android:id="@+id/container"
>     android:layout_width="match_parent"
>     android:layout_height="match_parent"
>     android:paddingTop="?attr/actionBarSize">
>
>     <fragment
>         <--...--> />
>
>     <com.google.android.material.bottomnavigation.BottomNavigationView
>         <--...--> />
>
>
> </androidx.constraintlayout.widget.ConstraintLayout>
>
> ```
>
> 여기서 아래의 옵션값을 지워준다.
>
> ```kotlin
> android:paddingTop="?attr/actionBarSize"
> ```
>
> 이 옵션을 지워주면 지도 상단의 여백을 꽉찬 지도 화면으로 볼 수가 있다.

### 💡 ViewModel을 통해 지도의 옵션을 통제하고 지도뷰 또한 띄우고자 한다?

> 이 부분은 MVVM패턴을 위해서 알아두면 좋을 듯하다. 그리고 정확한 방법인지는 모르나 사용해본 결과 아래와 같이 작성하면 가능하다는 것을 알게 되었다.
> 물론, databinding을 통해서 지도 Fragment를 가져오는 것은 안되지만, 다른 옵션들 좌표찍기, 버튼 추가하기 , 지도 옵션 만들기 등을 fragment 코드상이 아닌 viewmodel에서 통제가 가능해졌으므로 매우 유용하다고 생각한다.
>
> ```kotlin
> // fragment상에서는 viewmodel을 통해 지도 객체를 불러오는 것으로 해준다.
> class ThisFragment : Fragment(){
>
>    private lateinit var thisViewModel : ThisViewModel
>    // ...
>    override fnn onCreateView(...){
>        //...
>
>        thisViewModel.createMap(this)
>
>        return root
>    }
>    // ...
> }
> ```
>
> 다음은 viewmodel 에서 creatMap이라는 함수를 정의해주고, <br>
> onReadyMap 콜백 함수를 오버라이드 해주어서 좌표 객체도 추가해줘본다.
>
> ```kotlin
> class ThisViewModel : ViewModel(), OnMapReadyCallback {
>
>    // ...
>
>    fun createMap(frag : Fragment){
>        val mapFragment = frag.childFragmentManager.findFragmentById(R.id.map_naver_frag) as MapFragment?
>            ?: MapFragment.newInstance(
>                NaverMapOptions().camera(
>                    CameraPosition(
>                        NaverMap.DEFAULT_CAMERA_POSITION.target,
>                        NaverMap.DEFAULT_CAMERA_POSITION.zoom,
>                        30.0,
>                        45.0
>                    )
>                )
>            ).also {
>                frag.childFragmentManager.beginTransaction().add(R.id.map_naver_frag, frag).commit()
>            }
>        mapFragment.getMapAsync(this)
>    }
>
>    override fun onMapReady(naverMap: NaverMap) {
>        Marker().apply {
>            position = LatLng(37.5670135, 126.9783740)
>            map = naverMap
>        }
>
>        Marker().apply {
>            position = LatLng(37.57000, 126.97618)
>            icon = MarkerIcons.BLACK
>            angle = 315f
>            map = naverMap
>        }
>
>        Marker().apply {
>            position = LatLng(37.56500, 126.9783881)
>            icon = MarkerIcons.BLACK
>            iconTintColor = Color.RED
>            alpha = 0.5f
>            map = naverMap
>        }
>    }
> }
> ```
>
> 여기서 키포인트는 viewmodel에 callback함수를 상속시켜주고,
> 뷰모델상에서 지도의 데이터나 옵션 처리를 담당해준다. <br>
> (왜냐하면, 지도 객체에 지도의 좌표 값 즉, >데이터를 통제하고 관리해야 하는 경우가 있을 수 있기 때문이다.) <br>
> 이러한 이유 때문이라도, 추가적인 데이터 작업이 필요할 것이므로 viewmodel에서 이러한 작업이 될 수 있게 설계해주는 것이 좋다고 생각된다. <br>

> #### ✅ 좀더 정확하게 MVVM 패턴으로 지도 불러오고 옵션 넣기 
> 위의 방법으로도 지도가 불러지고 옵션을 추가할 수 있다. <br>
> 그러나 한가지 불편한 점은 viewmodel에서는 원칙상 fragment의 view에 대해 몰라도 되야하므로, fragment id를 불러서 fragment 위치를 설정하는 것은 좀 이상하다고  생각되었다. <br>
> 그래서 찾은 방법은 fragment transaction부분은 Fragment에서 진행하고, <br>
> 따로 지도의 설정만 viewmodel에서 할 수 있도록 구분하였다. 




### 💡 내 위치정보 권한 사용 방법
안드로이드 정책 상 사용자에게 위치 권한을 물어봐야한다. 
그래야 지도 상에 내 위치를 표시 할 수 있다. 

### 💡 지도 옵션 추가 및 MVVM 패턴으로 viewMode
