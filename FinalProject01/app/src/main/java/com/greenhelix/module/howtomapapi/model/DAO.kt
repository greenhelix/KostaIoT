package com.greenhelix.module.howtomapapi.model

import android.content.Context
import android.util.Log
import android.widget.Toast
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import com.greenhelix.module.howtomapapi.network.*
import kotlinx.coroutines.channels.awaitClose
import kotlinx.coroutines.flow.callbackFlow
import org.eclipse.paho.client.mqttv3.*
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject

class DAO {

    private lateinit var mqttClient : MQTTClient
    private val serverURI   = "tcp://test.mosquitto.org:1883"


    fun connectMQTT(context : Context) :String{
        var msg = ""
        mqttClient = MQTTClient(context, serverURI, "")
        mqttClient.connect("", "",
            object : IMqttActionListener {
                override fun onSuccess(asyncActionToken: IMqttToken?) {
                    Log.d("IK", "MQTT 연결성공")
                    Toast.makeText(context, "MQTT -> 연결 성공!", Toast.LENGTH_SHORT).show()
                    subscribeDB("kosta/coordinate")
                }

                override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                    Log.d("IK", "MQTT 연결실패: ${exception.toString()}")
                    Toast.makeText(context, "MQTT -> 연결 실패!: ${exception.toString()}", Toast.LENGTH_SHORT).show()
                }

            },
            object : MqttCallback {
                override fun messageArrived(topic: String?, message: MqttMessage?) {
                    // 여기가 진짜 메세지를 받는 부분이다!
                    msg = message.toString()
                    Log.d("IK", "DAO::connectMQTT::messageArrived::msg::\n$msg")
                    Toast.makeText(context, msg, Toast.LENGTH_SHORT).show()
                }

                override fun connectionLost(cause: Throwable?) {
                    Log.d("IK", "IK::Connection lost ${cause.toString()}")
                }

                override fun deliveryComplete(token: IMqttDeliveryToken?) {
                    Log.d("IK", "IK::Delivery complete")
                }
            }
        )

        Log.d("IK", "DAO::connectMQTT::result:: $msg")

        return msg
    }

//    fun parsePosData()= callbackFlow{
//
//        Log.d("IK", "DAO::parsePosData::dataPos:: $msg")
//        val temPos = mutableListOf<Mark>()
//
//        if(msg != ""){
//
//            try{
//                val jsonData = JSONObject(msg)
//                val jsonArray : JSONArray?= jsonData.optJSONArray("data")
//                var i = 0
//                while(i<jsonArray!!.length()){
//                    val jsonObject = jsonArray.getJSONObject(i)
//                    temPos.add(Mark(jsonObject.getString("marketID"), jsonObject.getString("coord")))
//                    i++
//                }
//            }catch (e: JSONException){
//                Log.d("IK", "$e")
//            }
//        }else{
//            Log.d("IK", "No dataPos in parsePosData()")
//        }
//        Log.d("IK", "DAO::parsePosData::temPos:: $temPos")
//        this.trySend(temPos)
//        awaitClose()
////        return temPos
//    }

    fun subscribeDB(topic : String){
        Log.d("IK", "topic:: $topic")
        if(mqttClient.isConnected()){
            mqttClient.subscribe(
                topic, 1,
                object : IMqttActionListener {
                    override fun onSuccess(asyncActionToken: IMqttToken?) {
                        Log.d("IK", "Success to subscribe: $topic")
                    }
                    override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                        Log.d("IK", "Failed to subscribe: $topic")
                    }
                })
        } else {
            Log.d("IK", "Impossible to subscribe, no server connected")
        }
    }

    fun disconnectMQTT(){
        if (mqttClient.isConnected()) {
            // Disconnect from MQTT Broker
            mqttClient.disconnect(object : IMqttActionListener {
                override fun onSuccess(asyncActionToken: IMqttToken?) {
                    Log.d("IK", "Disconnected")
                }

                override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                    Log.d("IK", "Failed to disconnect")
                }
            })
        } else {
            Log.d("IK", "Impossible to disconnect, no server connected")
        }
    }
}