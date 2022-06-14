package com.greenhelix.module.howtomapapi.model

data class Mark(var id: String,
                var sex : String,
                var num: Int,
                var percent: Int,
                var pos : String,
                var describe : String,
                var name : String
                ){

    constructor(): this("", "", 0,0,"","", ""){}
    constructor(id :String, pos:String) : this(id, "", 0,0,pos,"", ""){}
}
