import sqlite3

def init_db():
    conn = sqlite3.connect("orderbook.db")
    cursor = conn.cursor()
    
    cursor.execute('''CREATE TABLE IF NOT EXISTS orders (
                        id INTEGER PRIMARY KEY,
                        price REAL, 
                        quantity INTEGER, 
                        side TEXT)''')
                        
    cursor.execute('''CREATE TABLE IF NOT EXISTS trades (
                        id INTEGER PRIMARY KEY, 
                        price REAL, 
                        quantity INTEGER)''')

    conn.commit()
    conn.close()

def insert_order(price, quantity, side):
    conn = sqlite3.connect("orderbook.db")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO orders (price, quantity, side) VALUES (?, ?, ?)", (price, quantity, side))
    conn.commit()
    conn.close()

def fetch_orders():
    conn = sqlite3.connect("orderbook.db")
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM orders")
    orders = cursor.fetchall()
    conn.close()
    return orders
