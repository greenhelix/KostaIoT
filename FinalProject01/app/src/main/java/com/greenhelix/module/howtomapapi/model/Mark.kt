package com.greenhelix.module.howtomapapi.model

data class Mark(var id: Int,
                var sex : String,
                var num: Int,
                var percent: Int,
                var pos : String,
                var describe : String,
                var name : String
                ){

    constructor(): this(0, "", 0,0,"","", ""){}
    constructor(id :Int, pos:String) : this(0, "", 0,0,"","", ""){}
}
