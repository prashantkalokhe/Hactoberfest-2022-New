import pygsheets
import numpy as np

#Instance of the pygsheets package
client = pygsheets.authorize(service_account_file="GoogleSheetsAutomation\gsheetsauto12-1e72b300bddd.json")

print(client.spreadsheet_titles()) 

sps=client.open("Sample")
sh=sps.sheet1

arr=np.array([[1,2,3,4,5,6,7,8]])
# for i in range(8):
#     print(arr[i])

sh.update_value("B7",18)
sh.update_values("B2",["A",1,"B"])
