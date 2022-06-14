package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
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
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.flow.collect
import kotlinx.coroutines.launch
import org.eclipse.paho.client.mqttv3.*
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject

class MapViewModel : ViewModel()  {

    private val _stName = MutableLiveData<String>()
    private val _stDesc = MutableLiveData<String>()
    private val _stPercent = MutableLiveData<Int>()
    private val temp = mutableListOf<Mark>()
    private val _connectData = MutableLiveData<MutableList<Mark>>()
    private val _dataPos = MutableLiveData<String>()
    val dataPos : LiveData<String> = _dataPos
    var connectData : LiveData<MutableList<Mark>> = _connectData
    var stPercent : LiveData<Int> = _stPercent
    var stName : LiveData<String> = _stName
    val stDesc : LiveData<String> = _stDesc

    private val dao : DAO = DAO()
    private var data = ""

    fun conMQTT(context : Context) {
        viewModelScope.launch {
            _dataPos.value = dao.connectMQTT(context)
            Log.d("IK","MapViewModel::conMQTT::connectMQTT::result ${_dataPos.value}")

//            dao.parsePosData().collect{
//                Log.d("IK", "MapViewModel::parsePosData::connectMQTT::collectData:: $it")
//                _connectData.value = it
//            }
        }
    }

    fun disconnectMQTT(){ dao.disconnectMQTT() }

//    fun parsePosData():List<Mark>{
//
//        Log.d("IK", "connectMQTT::dataPos:: $dataPos")
//        val temPos = mutableListOf<Mark>()
//
//
//        try{
//            val jsonData = JSONObject(dataPos)
//            val jsonArray :JSONArray?= jsonData.optJSONArray("data")
//            var i = 0
//            while(i<jsonArray!!.length()){
//                val jsonObject = jsonArray.getJSONObject(i)
//                temPos.add(Mark(jsonObject.getString("marketID"), jsonObject.getString("coord")))
//                i++
//            }
//        }catch (e:JSONException){
//            Log.d("IK", "$e")
//        }
//
//
//        return temPos
//    }

    fun parseData(): List<Mark>{

//        if(data == ""){Log.d("IK", "no DATA")}

//        data = DATA2  // msg 가 들어온다.

        Log.d("IK", "parseData::DATA:: $data")

        try{
            val jsonData = JSONObject(data)
            val jsonArray :JSONArray?= jsonData.optJSONArray("data")
            var i = 0

            while(i<jsonArray!!.length()){
                val mark  = Mark()
                val jsonObject = jsonArray.getJSONObject(i)
                mark.id = jsonObject.getString("marketID")
                mark.num = jsonObject.getInt("num")
                mark.percent = jsonObject.getInt("percent")
                mark.pos = jsonObject.getString("coord")
                mark.describe = jsonObject.getString("name")
                mark.name = jsonObject.getString("describe")
                i++
                temp.add(mark)
            }

        }catch (e:JSONException){
            Log.d("IK", "$e")
        }
        return temp
    }

    fun getSize(){
//        return temp.size
    }

    fun showData(){
//        _stId.apply{
//            value = jsonObject.getInt("id")
//        }
//        for(i:Int in 0..temp.size){
//
//        }
    }
}
