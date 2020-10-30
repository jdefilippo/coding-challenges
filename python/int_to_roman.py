class Solution:
    def intToRoman(self, num: int) -> str:
        result = ""
        while(num>0):
            if num<4:
                result += "I"
                num -= 1
            elif num==4:
                result += "IV"
                num -= 4
            elif num>4 and num < 9:
                result += "V"
                num -= 5
            elif num==9:
                result += "IX"
                num -= 9
            elif num>9 and num < 40:
                result += "X"
                num -= 10
            elif num >= 40 and num < 50:
                result += "XL"
                num -= 40
            elif num >= 50 and num < 90:
                result += "L"
                num -= 50
            elif num >= 90 and num < 100:
                result += "XC"
                num -= 90
            elif num >= 100 and num < 400:
                result += "C"
                num -= 100
            elif num >= 400 and num < 500:
                result += "CD"
                num -= 400 
            elif num >= 500 and num < 900:
                result += "D"
                num -= 500
            elif num >= 900 and num < 1000: 
                result += "CM"
                num    -= 900 
            elif num >= 1000:
                result += "M"
                num    -= 1000

        return result
            