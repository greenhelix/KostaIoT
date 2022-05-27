package com.greenhelix.module.howtomapapi.ui.home

import android.animation.LayoutTransition
import android.os.Bundle
import android.os.PersistableBundle
import android.view.View
import android.widget.LinearLayout
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.isVisible
import androidx.transition.AutoTransition
import androidx.transition.TransitionManager
import com.greenhelix.module.howtomapapi.databinding.AdapterCardBinding

class CardAdapter : AppCompatActivity() {

    private lateinit var binding : AdapterCardBinding


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = AdapterCardBinding.inflate(layoutInflater)
        setContentView(binding.root)
        binding.viewLinear.layoutTransition.enableTransitionType(LayoutTransition.CHANGING)



    }

    private fun expandCard(view : View){
        binding.viewLinear.setOnClickListener {
            if (binding.viewLinearExpand.visibility == View.GONE) {
                TransitionManager.beginDelayedTransition(binding.root, AutoTransition())
                binding.viewLinearExpand.visibility = View.VISIBLE
            } else {
                TransitionManager.beginDelayedTransition(binding.root, AutoTransition())
                binding.viewLinearExpand.visibility = View.GONE
            }
        }
    }
}