// by default kotlin classes are final so can't inherit from them, need to make class open to allow inheritance
open class Product(name : String) : Sellable{
    // member variables need to be made open as well if they are to be overrided
    open var op = false
    open fun display()
    {
        println("product")
    }

    override var cost : Int = 0
    override fun incrementCost(){
        cost++
    }
}

// need to call the primary constructor of the superclass
class Electronic(name : String, battery : Int) : Product(name){
    override var op= true
    override fun display(){
        super.display() // can use properties of superclass using super keyword
        println("electronic")
    }
}

// interface is a contract to class, any class that implements the interface must override all its properties that don't already have an implementation
interface Sellable{
    var cost : Int 
    fun displayCost(){
        println(cost)
    }
    fun incrementCost()
}

// abstract classes, classes whose objects can't be created same as interfaces
// can be inherited but the classes which inherit it must implement its abstract properties, just like an interface
// but a class can inherit from only one class, no multiple inheritance
// but class can implement multiple interfaces
// abstract classes are classes so have constructors, interfaces don't
abstract class Something(){
    abstract position : Int 
    abstract fun lol()
    fun ded()
    {
        println("ded")
    }
}

fun main(){
    val p = Product("dancer")
    val e = Electronic("mobile", 200)
    p.display()
    e.display()
    println("${p.op}  ${e.op}")
}