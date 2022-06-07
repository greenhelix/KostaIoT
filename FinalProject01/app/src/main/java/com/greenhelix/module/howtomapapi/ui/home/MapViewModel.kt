package com.greenhelix.module.howtomapapi.ui.home

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class MapViewModel : ViewModel()  {

    private val _stName = MutableLiveData<String>().apply{
        value = "김익환 카페"
    }
    private val _stDesc = MutableLiveData<String>().apply{
        value = "여기는 가게 설명 샘플입니다. \n카페입니다. 여기는"
    }

    val stName : LiveData<String> = _stName
    val stDesc : LiveData<String> = _stDesc


}

//    private val _text = MutableLiveData<String>().apply {
//        value = "This is home Fragment"
//    }
//    val text: LiveData<String> = _text