// primary constructor written like this
class Human(name : String, age : Int){

    var email : String? = null

    // lateinit can be used if we want to intialize some property later, but must make sure that we intialize it before using
    lateinit var job : String

    var happiness = 0
    // can make custom getters and setters and even make them private
    get(){
        return field/2
    }
    set(value){
        // ternary operator ripoff
        field  = if(value>0) value else 0
    }

    // intializer, called when the object is created i.e. when primary constructor is called
    init {
        println("Human has name $name and age $age")
        job="unemployed"
    }

    // secondary constructor, it first calls the primary constructor
    constructor(name : String, age : Int, email : String?) : this(name,age){
        this.email = email
    }

}

// must have atleast one parameter in primary constructor
// need to specifiy val or var with the parameters as in data classes primary constructor can have only properties of the class as parameter
data class User(val name : String,val age : Int)

fun main(){
    var human = Human("big boi", 23)
    var h2 = Human("leety", 99, "email")
    h2.happiness = 11
    println(h2.happiness)
    // will compare all the data members
    println(human==h2)

    // data classes
    val c = User("lol",20)
    println(c.component1()) // return first parameter value, in this case it is name
    // can deconstruct data classes like this, i will store component1, j component2 and so on
    val (i,j) = c

    val a = Thing.Hello()
    val b = Thing().Bye()

    // Exception is problem or unexpected event that occurs during runtime and can hinder the flow of the program
    // Unchecked Exception are exceptions that are occur during runtime to problem in our code logic like NullPointerException
    // They extend from RuntimeException
    // Checked exceptions are exceptions that are caught during compile time like IOException
    // They extend from Throwable class

    // Exception handling invloves catching these exceptions when they occur to avoid any hindrance in the flow of the program

    // try block contains the code that can cause an exception
    try{
        // throw used to explicitly throw an exception
        throw Exception("u r nab")
    }
    // catch block contains the code that is executed when an exception is caught
    // can use different catch blocks for different types of exceptions
    catch(e : ArithmeticException){
        println("Arithmetic exception")
    }
    catch(e : Exception){
        e.printStackTrace()
        println("idk")
    }
    // finally block is executed even when exception does not occur
    finally{
        println("done ig")
    }
}

// can only access within the same file
private class Abc()

// can only access within the same module
internal class Bcd()

class Thing(){
    // nested class, class inside another class, can't access members of the upper class, static by default
    class Hello(){

    }

    // inner calss, class inside class but with inner keyword, can access members of upper class, can't be used in interfaces or nested classes, non static
    inner class Bye(){

    }
}