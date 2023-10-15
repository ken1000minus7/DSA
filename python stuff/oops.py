from abc import ABC, abstractmethod

class Human:
    # Class variable
    age = 20
    
    """ 
    In case of multipe constructors, last constructor is called, there is no constructor overloading
    """
    def __init__(self, name) -> None:
        # Instance variable
        self.name = name
        # Protected
        self._blood_group = "popo"
        # Private
        self.__weight = 100
        
    def abc(a):
        print(a)
        
class Sad:
    def cry(self):
        print("very sad")

# Multiple inheritance
class Me(Human, Sad):
    # Method overriding
    def cry(self):
        super().cry()
        print("aaaaaaaaaaaaa")
    
h = Human("ok")
b = Human("bye")
print(h.name)

print(h.__dict__)

m = Me("idk")
m.cry()

# An abstract base class
# interface is a skem, use duck typing or something
class Car(ABC):
    def drive(self):
        pass
    
class RacingCar(Car):
    def drive(self):
        print("vroooooooooom")
        
c = RacingCar()
c.drive()