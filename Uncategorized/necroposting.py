from datetime import datetime

a = datetime.strptime(input(), "%Y/%m/%d")
b = datetime.strptime(input(), "%Y/%m/%d")
print(abs((a-b).days))