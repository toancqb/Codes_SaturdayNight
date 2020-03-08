#

pets = ('bird', 'snake', 'dog', 'turtle', 'cat', 'hamster')

#old way:
old_way_list = []
for pet in pets:
    old_way_list.append(pet.upper())
print(old_way_list)

#List comprehension

lst_pets = [pet.upper() for pet in pets]
print(lst_pets)

#List comprehension with conditions
#  [expression for item in iterable if some_condition]
#
#   expand form:
#   for item in iterable:
#       if some_condition:
#           expression
#

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
square_primes = [x*x for x in primes if x%10 == 3]
print(square_primes)

test = []
for x in primes:
    if x%10 == 3:
        test.append(x*x)
print(test)

#We can replace some_condition with function
def has_four_leg(pet):
    return pet in ('pig', 'dog', 'turtle', 'hamster', 'cat')

four_leg_pets = [pet.upper() for pet in pets if has_four_leg(pet)]
print(four_leg_pets)

# [expression0 if some_condition else expression1 for item in iterable]
#
max_value = 10
numbers = (7, 9, 11, 4, 3, 2, 12)
