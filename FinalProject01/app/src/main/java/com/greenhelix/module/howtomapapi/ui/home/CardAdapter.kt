package com.greenhelix.module.howtomapapi.ui.home

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.greenhelix.module.howtomapapi.databinding.AdapterCardBinding

class CardAdapter : AppCompatActivity() {

    private lateinit var binding : AdapterCardBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = AdapterCardBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.showDataProgress.apply {
            progress = 60
        }

    }

}