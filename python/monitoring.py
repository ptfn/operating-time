from tkinter import *  
from tkinter.ttk import Progressbar
import psutil as ps  

tk = Tk()
tk.title("Task Manager")  

# --System--

memory = ps.virtual_memory()
disk = ps.disk_usage('/')
disk_rw = ps.disk_io_counters()
network = ps.net_io_counters()

cpu = ps.cpu_percent(interval=1)
mem = memory.percent
disk = disk.percent

# --Label--

cpu_ui = Label(tk, text="CPU:", font=("Arial Bold", 20))  
cpu_ui.grid(column=0, row=0) 

mem_ui = Label(tk, text="Mem:", font=("Arial Bold", 20))  
mem_ui.grid(column=0, row=1)

disk_ui = Label(tk, text="Disk:", font=("Arial Bold", 20))  
disk_ui.grid(column=0, row=2) 

# ---Label-Back---

cpu_ui = Label(tk, text=" %", font=("Arial Bold", 20))  
cpu_ui.grid(column=2, row=0) 

mem_ui = Label(tk, text=" %", font=("Arial Bold", 20))  
mem_ui.grid(column=2, row=1)

disk_ui = Label(tk, text=" %", font=("Arial Bold", 20))  
disk_ui.grid(column=2, row=2) 

# ---Progressbar---

cpu_bar = Progressbar(tk, length=230) 
cpu_bar.grid(column=1, row=0)

mem_bar = Progressbar(tk, length=230)
mem_bar.grid(column=1, row=1)

disk_bar = Progressbar(tk, length=230) 
disk_bar.grid(column=1, row=2)

cpu_bar['value'] = cpu  
mem_bar['value'] = mem  
disk_bar['value'] = disk  

tk.geometry('350x150')
tk.mainloop()
