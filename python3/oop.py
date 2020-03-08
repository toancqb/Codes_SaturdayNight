# Learn python 3 OOP

#1.What's Class?
#- Class is a structure of datas and functions
#- A class is a mechanism used to create new user-defined
# data structures. It contains data as well as
# the methods used to process that data.
#2.What's an instance?
#- An instance is the actual data of Class
#- An instance is a copy of the class with actual values,
# literally an object of a specific class.
#3.What's the relationship between a class and an instance?
#- Class is the reference of Instance
#- While a class is a blueprint used to describe how to make something,
# instances are objects created from those blueprints.
#4.What's the Python syntax used for defining a new class?
#- class NameClass():
#5.What’s the spelling convention for a class name?
#- CamelCase notation, starting with a capital letter
#- i.e., PythonClassName()
#6.How do you instantiate, or create an instance of, a class?
#- You use the the class name, followed by parentheses.
#  So if the class name is Dog(),
#  an dog instance would be - my_class = Dog().
#7.How do you access the attributes and behaviors of a class instance?
#- With dot notation - e.g., instance_name.attribute_name
#8.What’s a method?
#- A function that’s defined inside a class.
#9.What’s the purpose of self?
#- The first argument of every method references the current instance
#  of the class, which by convention, is named self.
#  In the __init__ method, self refers to the newly created object;
#   while in other methods, self refers to the instance
#   whose method was called. For more on __init__ vs. self,
#   check out this article.
#   (https://stackoverflow.com/questions/625083/what-init-and-self-do-on-python/625098#625098)
#10.What’s the purpose of the __init__ method?
#- The __init__ method initializes an instance of a class.
#11.Describe how inheritance helps prevent code duplication.
#- Child classes inherit all of the parent’s attributes and behaviors.
#12.Can child classes override properties of their parents?
#- Yes

class Dog():
    #Class Attribute
    species = 'mammal'
    sound = ''
    is_hungry = True

    # Initializer / Instance Attributes
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def info(self):
        print("======================")
        print("= Name:",self.name)
        print("= Age:",self.age)
        print("= Species:",self.species)
        print("======================")

    def speak(self,sound):
        self.sound = sound
        print(self.name,sound)

    def eat(self):
        self.is_hungry = False

class BullDog(Dog):
    def run(self, speed):
        print(self.name, "runs", speed)

def get_biggest_number(*args):
    return max(args)

class Pets():
    dogs = []
    def __init__(self, dogs):
        self.dogs = dogs

    def desciption(self):
        for i in self.dogs:
            i.speak("Gau Gau")
            i.info()

if __name__ == '__main__':
    a = Dog('Tom', 6)
    b = BullDog('Fletcher', 7)
    c = Dog('Larry', 9)
    pet = Pets([a,b,c])
    pet.desciption()
