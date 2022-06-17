package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
import android.content.Intent
import android.os.Handler
import android.util.Log
import android.widget.Toast
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import androidx.navigation.fragment.findNavController
import com.greenhelix.module.howtomapapi.R
import com.greenhelix.module.howtomapapi.model.DAO
import com.greenhelix.module.howtomapapi.model.DATA2
import com.greenhelix.module.howtomapapi.model.Mark
import com.greenhelix.module.howtomapapi.network.MQTTClient
import kotlinx.coroutines.*
import kotlinx.coroutines.channels.awaitClose
import kotlinx.coroutines.flow.callbackFlow
import kotlinx.coroutines.flow.collect
import org.eclipse.paho.client.mqttv3.*
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject

class MapViewModel : ViewModel()  {

    private val _stName = MutableLiveData<String>()
    private val _stDesc = MutableLiveData<String>()
    private val _stPercent = MutableLiveData<Int>()


    private var markers : MutableList<Mark> = mutableListOf()
    private var infoWindows : MutableList<Mark> = mutableListOf()


    var stPercent : LiveData<Int> = _stPercent
    var stName : LiveData<String> = _stName
    val stDesc : LiveData<String> = _stDesc

    private var  dao : DAO = DAO()
    private var data = ""

    fun conMQTT(context : Context)  {
        viewModelScope.launch(Dispatchers.IO) {  dao.connectMQTT(context) }
    }

    fun disconnectMQTT(){ dao.disconnectMQTT() }


    fun parseData(){

        viewModelScope.launch {
            withTimeout(3000){
                dao.getData().collect{
                    data = it
                }
            }
        }

        Log.d("IK", "MapViewModel::parsePosData:: $data")
        if(data != ""){
            val jsonData = JSONObject(data)
            val jsonArray :JSONArray?= jsonData.optJSONArray("data")
            var i = 0
            while(i<jsonArray!!.length()){
                val jsonObject = jsonArray.getJSONObject(i)
                if(jsonObject.length() == 2){
                    markers.add(Mark(jsonObject.getString("marketID"), jsonObject.getString("coord")))
                }
                else if(jsonObject.length() > 2){
                    markers.add(Mark(jsonObject.getString("marketID"),
                        jsonObject.getString("coord"),
                        jsonObject.getString("marketName"),
                        jsonObject.getString("about"),
                        jsonObject.getInt("ratio")
                    ))
                }
                i++
            }
            Log.d("IK", "MapViewModel::parsePosData::🔽🔽\n$markers")
        }
    }

    fun makeMarks()= callbackFlow {
        trySend(markers)
        awaitClose()
    }

//    fun parseData(){
//        viewModelScope.launch {
//            withTimeout(10000){
//                dao.getData().collect{
//                    data = it
//                }
//            }
//        }
//
//        Log.d("IK", "parseData::DATA:: $data")
//
//        val jsonData = JSONObject(data)
//        val jsonArray :JSONArray?= jsonData.optJSONArray("data")
//        var i = 0
//        while(i<jsonArray!!.length()){
//            val jsonObject = jsonArray.getJSONObject(i)
//            infoWindows.add(Mark(jsonObject.getString("marketID"), jsonObject.getString("marketName"),
//            jsonObject.getString("about"), jsonObject.getInt("ratio")))
//            i++
//        }
//        Log.d("IK", "MapViewModel::parseData::🔽🔽\n$infoWindows")
//    }

    fun getSize(): Int{
        return markers.size
    }

}
