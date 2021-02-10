from statistics import mean
from decimal import Decimal,ROUND_HALF_UP
from math import sqrt
from IPython.display import HTML, display

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

def getRelativeError(data):
    dataMean = mean(data)
    temp = data
    absoleteErrors = list(map(lambda dataPoint: dataPoint - dataMean, temp))
    relativeErrors = list(map(lambda dataPoint: abs(dataPoint / dataMean), absoleteErrors)) # is abs necessary?
    return mean(relativeErrors)

def dataToTable(data, columns = None):
    if len(data) == 0 :  
        display(HTML('<b>Нема данних</b>'))
        return
    
    hdr = ''
    if columns != None:
        for col in columns: # Формируем заголовок таблицы
            hdr = hdr + '<th>' + col + '</th>'
            
        hdr = '<tr>' + hdr + '</tr>'

    dt = ''
    for row in data: # Проходим циклом по всем строкам
        dt = dt + '<tr>'
        for cell in row: # И формируем тело таблицы
        	if isinstance(cell, Interable) :
        		for e in cell:
        			dt = dt + '<td>' + str(e) + '</td>'
            else:
            	dt = dt + '<td>' + str(cell) + '</td>'
        dt = dt + '</tr>'
            
    display(HTML('<table>' + hdr + dt + '</table>')) # Выводим таблицу на экран

dataToTable(tabledata, columns=["Номер досліду","h, м", "t, c", "<t>, c", "t^{2}, c^{2}"])