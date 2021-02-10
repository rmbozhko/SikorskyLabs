from statistics import mean
from decimal import Decimal,ROUND_HALF_UP
from math import sqrt
from IPython.display import HTML, display

def getMean(data):
    ten_places = Decimal('0.0000000001')
    four_places = Decimal('0.0001')
    dataMean = []
    for dataPoints in data:
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

def getRelativeError(data):
    dataMean = mean(data)
    temp = data
    absoleteErrors = list(map(lambda dataPoint: dataPoint - dataMean, temp))
    relativeErrors = list(map(lambda dataPoint: abs(dataPoint / dataMean), absoleteErrors))
    return relativeErrors
from statistics import mean
from decimal import Decimal,ROUND_HALF_UP
from math import sqrt
from IPython.display import HTML, display

def getMean(data):
    ten_places = Decimal('0.0000000001')
    four_places = Decimal('0.0001')
    dataMean = []
    for dataPoints in data:
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

def getRelativeError(data):
    dataMean = mean(data)
    temp = data
    absoleteErrors = list(map(lambda dataPoint: dataPoint - dataMean, temp))
    relativeErrors = list(map(lambda dataPoint: abs(dataPoint / dataMean), absoleteErrors))
    return relativeErrors
