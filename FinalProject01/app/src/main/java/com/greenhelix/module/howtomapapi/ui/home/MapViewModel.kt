package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
import android.util.Log
import android.widget.Toast
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.navigation.fragment.findNavController
import com.greenhelix.module.howtomapapi.R
import com.greenhelix.module.howtomapapi.model.DAO
import com.greenhelix.module.howtomapapi.model.DATA2
import com.greenhelix.module.howtomapapi.model.Mark
import com.greenhelix.module.howtomapapi.network.MQTTClient
import org.eclipse.paho.client.mqttv3.*
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject

class MapViewModel : ViewModel()  {

    private val _stName = MutableLiveData<String>()
    private val _stDesc = MutableLiveData<String>()
    private val _stPercent = MutableLiveData<Int>()
    private val _stSex = MutableLiveData<String>()
    private val _stId = MutableLiveData<Int>()
    private val temp = mutableListOf<Mark>()
    var stId : LiveData<Int> = _stId
    var stSex : LiveData<String> = _stSex
    var stPercent : LiveData<Int> = _stPercent
    var stName : LiveData<String> = _stName
    val stDesc : LiveData<String> = _stDesc

    private lateinit var mqttClient : MQTTClient
    private val dao : DAO = DAO()
    private var data = ""
    private var dataPos = ""

    fun connectMQTT(context : Context) {
        mqttClient = dao.connectMQTT(context)
        data = dao.subscribeDB("kosta/data")  // 일단은 val 로 설정
        dataPos = dao.subscribeDB("kosta/coordinate")

        Log.d("IK", "connectMQTT::DATA:: $data")

        Log.d("IK", "connectMQTT::DATA:: $dataPos")
    }

    fun disconnectMQTT(){ dao.disconnectMQTT() }

    fun parsePosData():List<Mark>{
        val temPos = mutableListOf<Mark>()

        try{
            val jsonData = JSONObject(dataPos)
            val jsonArray :JSONArray?= jsonData.optJSONArray("coordinate")
            var i = 0
            while(i<jsonArray!!.length()){
                val jsonObject = jsonArray.getJSONObject(i)
                temPos.add(Mark(jsonObject.getInt("id"), jsonObject.getString("latLng")))
                i++
            }
        }catch (e:JSONException){
            Log.d("IK", "$e")
        }

        return temPos
    }

    fun parseData() {

//        if(data == ""){Log.d("IK", "no DATA")}

        data = DATA2  // msg 가 들어온다.

        Log.d("IK", "parseData::DATA:: $data")

        try{
            val jsonData = JSONObject(data)
            val jsonArray :JSONArray?= jsonData.optJSONArray("data")
            var i = 0

            while(i<jsonArray!!.length()){
                val mark  = Mark()
                val jsonObject = jsonArray.getJSONObject(i)
                mark.id = jsonObject.getInt("marketID")
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
    }

//    fun getSize():Int{
//        return temp.size
//    }

    fun showData(){
//        _stId.apply{
//            value = jsonObject.getInt("id")
//        }
        for(i:Int in 0..temp.size){

        }
    }
}
