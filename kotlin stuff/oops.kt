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
}