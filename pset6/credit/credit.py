from cs50 import get_string


def main():
    number = get_string("Number: ")

    isAmex = checkAmex(number)
    isMasterCard = checkMasterCard(number)
    isVisa = checkVisa(number)

    if(not(isVisa or isMasterCard or isAmex)):
        print("INVALID")
        return

    isValid = luhns(number)

    if isValid:
        if(isAmex):
            print("AMEX")
            return
        if(isMasterCard):
            print("MASTERCARD")
            return
        if(isVisa):
            print("VISA")
            return
    else:
        print("INVALID")


def luhns(number):
    total = 0
    counter = 1
    for digitS in reversed(number):
        digit = int(digitS)
        if counter % 2 == 0:
            product = digit * 2
            productS = str(product)

            if len(productS) > 1:
                total += int(productS[0])
                total += int(productS[1])
            else:
                total += product
        else:
            total += digit
        counter += 1
    totalS = str(total)
    last = int(totalS[-1])
    if (last == 0):
        return True
    return False

# amex starts with 34 or 37 and is 15 digits


def checkAmex(number):
    return number[0] == '3' and (number[1] == '4' or number[1] == '7') and len(number) == 15

# mastercard starts with 51-55 and is 16 digits


def checkMasterCard(number):
    secondDigit = int(number[1])
    return number[0] == '5' and secondDigit > 0 and secondDigit < 6 and len(number) == 16

# visa starts with 4 and is 13 or 16 digits


def checkVisa(number):
    return number[0] == '4' and (len(number) == 13 or len(number) == 16)


main()

