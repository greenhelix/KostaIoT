package com.greenhelix.module.howtomapapi.model

import android.content.Context
import android.util.Log
import android.widget.Toast
import com.greenhelix.module.howtomapapi.network.MQTTClient
import org.eclipse.paho.client.mqttv3.*

class DAO {

    private lateinit var mqttClient : MQTTClient
    private val serverURI : String = "tcp://test.mosquitto.org:1883"

    fun connectMQTT(context : Context) : MQTTClient{

        mqttClient = MQTTClient(context, serverURI, "")

        mqttClient.connect("", "",
            object : IMqttActionListener {
                override fun onSuccess(asyncActionToken: IMqttToken?) {
                    Log.d(this.javaClass.name, "Connection success")

                    Toast.makeText(context, "MQTT Connection success", Toast.LENGTH_SHORT).show()
                }

                override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                    Log.d(this.javaClass.name, "Connection failure: ${exception.toString()}")

                    Toast.makeText(context, "MQTT Connection fails: ${exception.toString()}", Toast.LENGTH_SHORT).show()
                }
            },
            object : MqttCallback {
                override fun messageArrived(topic: String?, message: MqttMessage?) {
                    val msg = "Receive message: ${message.toString()} from topic: $topic"
                    Log.d(this.javaClass.name, msg)

                    Toast.makeText(context, msg, Toast.LENGTH_SHORT).show()
                }

                override fun connectionLost(cause: Throwable?) {
                    Log.d(this.javaClass.name, "Connection lost ${cause.toString()}")
                }

                override fun deliveryComplete(token: IMqttDeliveryToken?) {
                    Log.d(this.javaClass.name, "Delivery complete")
                }
            }
        )
        return mqttClient
    }

    fun subscribeDB(table : String) : String {
        var subscribeData = ""
        if(mqttClient.isConnected()){
            mqttClient.subscribe(
                table, 1,
                object : IMqttActionListener {
                    override fun onSuccess(asyncActionToken: IMqttToken?) {
                        val msg = "Subscribed to: $table"
                        Log.d(this.javaClass.name, "Success to subscribe: $table")
                        Log.d(this.javaClass.name, msg)
                        subscribeData = msg
                    }

                    override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                        Log.d(this.javaClass.name, "Failed to subscribe: $table")
                    }
                })
        } else {
            Log.d(this.javaClass.name, "Impossible to subscribe, no server connected")
        }

        return subscribeData
    }

    fun disconnectMQTT(){
        if (mqttClient.isConnected()) {
            // Disconnect from MQTT Broker
            mqttClient.disconnect(object : IMqttActionListener {
                override fun onSuccess(asyncActionToken: IMqttToken?) {
                    Log.d(this.javaClass.name, "Disconnected")
                }

                override fun onFailure(asyncActionToken: IMqttToken?, exception: Throwable?) {
                    Log.d(this.javaClass.name, "Failed to disconnect")
                }
            })
        } else {
            Log.d(this.javaClass.name, "Impossible to disconnect, no server connected")
        }
    }
}