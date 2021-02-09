from statistics import mean
from decimal import Decimal,ROUND_HALF_UP
from math import sqrt


def getMean(data):
    ten_places = Decimal('0.0000000001')
    four_places = Decimal('0.0001')
    dataMean = []
    for dataPoints in data:
        #dataMean.append(Decimal(mean(dataPoints)).quantize(ten_places).quantize(four_places, rounding=ROUND_HALF_UP))
        dataMean.append(mean(dataPoints))
    return dataMean

def getMSE(arr):
    dataMean = mean(arr)
    result = 0
    n = len(arr)
    for dataPoint in arr:
        result = result + ((dataPoint - dataMean) ** 2)
    result = sqrt(result/(n * (n - 1)))
    return result

# TO-DO: Check the main flow
def getRelativeError(data):
    n = len(data)
    dataMean = mean(data)
    temp = data
    absoleteError = sum(list(map(lambda dataPoint: dataPoint - dataMean, temp)))
   	#absoleteError = temp / n
    temp = data
    relativeError = list(map(lambda dataPoint: absoleteError / dataPoint, temp))
    return relativeError
    