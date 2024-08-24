have_big = False
have_small = False
text = input()
for char in text:
    if char.isupper():
        have_big = True
    elif char.islower():
        have_small = True
        

if have_big and (not have_small):
    print("All Capital Letter")
elif (not have_big) and have_small:
    print("All Small Letter")
else :
    print("Mix")