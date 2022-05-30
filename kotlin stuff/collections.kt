fun main(){
    // make array like this, can have different types or same type dsnt matter, can;t change sizze
    val a = arrayOf(1,2,"ok")
    val b = arrayOf<String>("a","b") // can specify type like this
    println(a.contentToString())
    
    // lists are immutable
    val c = listOf(1,2,3,4)
    
    // can add items in mutable lists
    val d= c.toMutableList()
    val e = mutableListOf("ok","bye")
    e.add("element")

    println(e)

    // sets used for storing unique values, mutable sets are mutable, unordered by default
    val f = setOf(1,2,3,4,5)
    val g = mutableSetOf(323,23,1)
    g.add(49)
    println(g.sorted())

    // maps for key value stuff, mutable maps mutable, unordered
    val h = mapOf("ok" to 90, "bye" to 140)
    println(h)

    // mutable array, pretty much same as mutable list
    val i =arrayListOf(1,2,3)
    val j = i.iterator()
    while(j.hasNext())
    {
        println(j.next())
    }
}