import gspread

client=gspread.service_account(filename="GoogleSheetsAutomation\gsheetsauto12-1e72b300bddd.json")
sps=client.open_by_key("Provide Key of sheets")

sh=sps.sheet1
sh.append_row(["Aurobinda",21,"EEE"])

