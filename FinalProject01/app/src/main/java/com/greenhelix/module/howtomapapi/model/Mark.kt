package com.greenhelix.module.howtomapapi.model

data class Mark constructor(var marketID: String,
                var pos : String,
                var marketName : String ="",
                var about : String ="",
                var ratio: Int = 0
                ){

//constructor(id :String, pos:String) : this(id, pos,"","", 0)
//constructor(id :String, pos:String, marketName:String, about:String, ratio:Int):this(id, pos, marketName, about, ratio)
}
