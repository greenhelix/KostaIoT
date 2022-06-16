package com.greenhelix.module.howtomapapi.model

import android.content.Context
import android.content.Intent
import android.util.Log
import android.widget.Toast
import androidx.core.content.ContextCompat.startActivity
import com.greenhelix.module.howtomapapi.network.*
import com.greenhelix.module.howtomapapi.ui.home.MapViewModel
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.channels.awaitClose
import kotlinx.coroutines.flow.callbackFlow
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import org.eclipse.paho.client.mqttv3.*

class DAO {

    private lateinit var mqttClient : MQTTClient
    private val serverURI   = "tcp://test.mosquitto.org:1883"
    var msg = ""

    fun connectMQTT(context : Context) {

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
                    if (topic == "kosta/coordinate"){
                        Log.d("IK", "DAO::connectMQTT::messageArrived::msg::\n$message")
                        Toast.makeText(context, "DATA\n$message", Toast.LENGTH_SHORT).show()

                        msg = message.toString()

                    }else{
                        Log.d("IK", "DAO::connectMQTT::messageArrived::msg:: not yet")
                    }

                }

                override fun connectionLost(cause: Throwable?) {
                    Log.d("IK", "IK::Connection lost ${cause.toString()}")
                }

                override fun deliveryComplete(token: IMqttDeliveryToken?) {
                    Log.d("IK", "IK::Delivery complete")
                }
            }
        )

    }


    fun getData() = callbackFlow {
        trySend(msg)
        awaitClose()
    }

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