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
import com.greenhelix.module.howtomapapi.network.MQTTClient
import org.eclipse.paho.client.mqttv3.*
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject

class MapViewModel : ViewModel()  {

    private val _stName = MutableLiveData<String>()
    private val _stDesc = MutableLiveData<String>()
    val stName : LiveData<String> = _stName
    val stDesc : LiveData<String> = _stDesc

    private lateinit var mqttClient : MQTTClient
    private val dao : DAO = DAO()
    private var data = ""

    fun connectMQTT(context : Context) {
        mqttClient = dao.connectMQTT(context)
        data = dao.subscribeDB()  // 일단은 val 로 설정
        Log.d("IK", "connectMQTT::DATA:: $data")
    }

    fun disconnectMQTT(){ dao.disconnectMQTT() }

    fun parseData(){
        val sample = "{\n" +
                "  \"data\": [\n" +
                "    {\n" +
                "      \"id\": 1,\n" +
                "      \"sex\": \"m\",\n" +
                "      \"num\": 1\n" +
                "    },\n" +
                "    {\n" +
                "      \"id\": 2,\n" +
                "      \"sex\": \"w\",\n" +
                "      \"num\": 2\n" +
                "    },\n" +
                "    {\n" +
                "      \"id\": 3,\n" +
                "      \"sex\": \"w\",\n" +
                "      \"num\": 3\n" +
                "    },\n" +
                "    {\n" +
                "      \"id\": 4,\n" +
                "      \"sex\": \"w\",\n" +
                "      \"num\": 4\n" +
                "    }\n" +
                "  ]\n" +
                "}"

        if(data == ""){
            Log.d("IK", "no DATA")
        }
        data = sample
        Log.d("IK", "parseData::DATA:: $data")
        try{
            val jsonData = JSONObject(data)
            val jsonArray :JSONArray?= jsonData.optJSONArray("data")
            var i = 0
            var tempData = ""
            while(i<jsonArray!!.length()){
                val jsonObject = jsonArray!!.getJSONObject(i)

                val id = jsonObject.getString("id")
                val sex = jsonObject.getString("sex")
                val num = jsonObject.getString("num")
                tempData = "ID: $id \n 성별: $sex \n 번호: $num"
                i++
                Log.d("IK", tempData)
            }
        }catch (e:JSONException){
            Log.d("IK", "$e")
        }
        _stName.apply{
            value = "김익환 카페"
        }
        _stDesc.apply{
            value = "여기는 가게 설명 샘플입니다. \n카페입니다. 여기는"
        }

    }
}
