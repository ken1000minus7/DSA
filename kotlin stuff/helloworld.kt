// main function, entry point of the program
fun main(){
    // can be reassigned
    var a =10

    // can't be reassigned
    val b= 12

    // type inferred automatically, don't hv to specify
    // can explicitly specify type like this if required
    val c : String = "Hello"

    val d : Long = 23_222_222_222 // can add underscores to make more readable

    // string template expression 
    val hello = "Hello $c with length ${c.length}"

    // print
    println(hello)

    // when is switch ripoff
    when(b)
    {
        0 -> {
            println("idk")
        }
        // multiple values
        1,2,3 -> {
            println("lol")
        }
        // range of values
        in 4..10 ->{
            println("pop")
        }
        // check type
        is Int -> {
            println("hahaha")
        }
        // not
        !in 6..10 ->{
            println("ijensdkfnskdl")
        }
        // default
        else -> println("aaaaaaaaaaaaaaa")
    }

    // iterating range, 5 included
    for(i in 1..5){
        println(i)
    }
    // 5 not included
    for(i in 1 until 5){
        println(i)
    }
    // decrementing
    for(i in 5 downTo 1 step 2){
        println(i)
    }
    // can use step to change the increment or decrement step

    println(add(4,3))

    // nullables - variables that can have a null value, ? added along with type to specify that it is nullable
    var ok : String? = "Hello"
    ok = null

    // null safe call, will return the value if variable is not null otherwise will return null, no need to write if else and all
    var size = ok?.length

    // can use this instead of that if else null check for executing some code if not null
    ok?.let { println("loki") }

    // elvis operator, used to return a default value in case variable is null when storing value in non null type
    val hehe = ok ?: "nab"

    // asserted non null, converts a null type to non null type but will give NullPointerException if the variable is null so be careful
    ok = "i"
    val haha = ok!!

    // smart implicit casting
    val ono : Any = "ok"

    // explicit unsafe casting
    val lol = ono as String

    // explicit safe casting, will return null if type casting goes wrong
    val hhh = ono as? String

    println(hhh)

    // lambda expressions, function literals use functions in expressions
    val aa : (Int,Int) -> Int = { a , b ->
        a+b
    }
    println(aa(3,4))
    
    // rest all mostly java ripoff ez hehe
}

// write parameters and return type like this
fun add(a : Int, b: Int) : Int{
    // parametes are val so can't be reassigned
    return a+b
}
// method is just function that is attached to an object