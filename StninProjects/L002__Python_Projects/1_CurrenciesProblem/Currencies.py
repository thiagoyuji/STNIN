#This Program is a Method that calculate a minor quantity of currencies in 2
#kinds of money values.

#Imports :: Start

import os

#Imports :: End

#Functions :: Start

def GetMajorCurrent(NoteOne, NoteTwo):

    if(NoteOne >= NoteTwo):
        return NoteOne, NoteTwo
    else:
        return NoteTwo, NoteOne

def CalculateMinorQuantityOfNotes(MajorCurrent,MinorCurrent,ValueToBeCalculate):

    Quociente = ValueToBeCalculate / MajorCurrent
    Count = 0
    CheckCurrentValue = 0

    while(CheckCurrentValue != ValueToBeCalculate):

        CountMajorCurrent = Quociente - Count
        CountMinorCurrent = 0
        CheckCurrentValue = (Quociente - Count) * MajorCurrent
        
        while(CheckCurrentValue < ValueToBeCalculate):

            CheckCurrentValue += MinorCurrent
            CountMinorCurrent += 1

        Count += 1

    if(CountMajorCurrent < 0 or CountMinorCurrent < 0):
        return 0,0
    else:
        return CountMajorCurrent, CountMinorCurrent

#Functions :: End

#Menu :: Start

os.system('clear')

print "This Program Calculate a minor value of currencies in 2 "
print "Kinds of Currencies.\n\n"

print "1 -> Execute Program."
print "2 -> Exit.\n\n"

MenuStatus = input("Insert Options >> ")

#Menu :: End

#Inputs :: Start

if(MenuStatus == 1):

    os.system('clear')
    NoteValueOne = input("Insert a Money Value >>  ")
    NoteValueTwo = input("Insert a Money Value >>  ")

    MoneyValue = input("Insert a Quantity of Money >> ")

    MajorNote, MinorNote = GetMajorCurrent(NoteValueOne,NoteValueTwo)

    QuantityOfMajorNote, QuantityOfMinorNote = CalculateMinorQuantityOfNotes(MajorNote,MinorNote,MoneyValue)

    print "Value >> " + str(MoneyValue) + " >> "
    print "Has " + str(QuantityOfMajorNote) + " Notes of R$" + str(MajorNote)
    print "Has " + str(QuantityOfMinorNote) + " Notes of R$" + str(MinorNote)

else:

    os.system('clear')
    print "\nExit Successful\n\n"

#Inputs :: End

#End of Program
