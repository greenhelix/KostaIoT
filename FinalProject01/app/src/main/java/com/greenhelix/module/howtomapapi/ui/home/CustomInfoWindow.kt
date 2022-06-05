package com.greenhelix.module.howtomapapi.ui.home

import android.content.Context
import android.view.LayoutInflater
import android.widget.LinearLayout
import com.greenhelix.module.howtomapapi.R

class CustomInfoWindow(context: Context) : LinearLayout{

    private fun initCustomView(context: Context){
        val view = LayoutInflater.from(context).inflate(R.layout.window_info_custom, this, false)

    }



}