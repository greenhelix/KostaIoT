package com.greenhelix.module.howtomapapi.model

data class Mark(var marketID: String,
                var pos : String,
                var marketName : String,
                var about : String,
                var ratio: Int
                ){

    constructor(id :String, pos:String) : this(id, pos,"","", 0)
    constructor(id :String, name:String, describe:String, percent:Int):this(id, "", name, describe, percent)
}
