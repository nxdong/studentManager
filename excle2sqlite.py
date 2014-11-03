__author__ = 'principle'
import xlrd
import sqlite3
conn = sqlite3.connect('gradetest.db')
cc = conn.cursor()
cc.execute("create table student (id integer primary key,name text )")
data = xlrd.open_workbook('excel.xls')
table = data.sheet_by_index(0)
nRows = table.nrows
for i in range(2,nRows-6):
    print(table.row_values(i))
    idStr = table.cell(i,0).value
    id = int(idStr)
    name = table.cell(i,1).value
    insertItem = [id,name]
    print(insertItem)
    cc.execute("INSERT INTO student VALUES (?,?)",(id,name,) )
conn.commit()
