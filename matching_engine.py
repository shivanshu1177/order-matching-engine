import heapq

class OrderBook:
    def __init__(self):
        self.bids = []  # Max-heap for buy orders
        self.asks = []  # Min-heap for sell orders

    def add_order(self, price, quantity, side):
        if side == "buy":
            heapq.heappush(self.bids, (-price, quantity))  # Max-heap for highest bid
        else:
            heapq.heappush(self.asks, (price, quantity))  # Min-heap for lowest ask

    def match_orders(self):
        trades = []
        while self.bids and self.asks and -self.bids[0][0] >= self.asks[0][0]:
            bid_price, bid_qty = heapq.heappop(self.bids)
            ask_price, ask_qty = heapq.heappop(self.asks)
            trade_qty = min(bid_qty, ask_qty)
            trades.append((ask_price, trade_qty))  # Match at ask price
            if bid_qty > trade_qty:
                heapq.heappush(self.bids, (bid_price, bid_qty - trade_qty))
            if ask_qty > trade_qty:
                heapq.heappush(self.asks, (ask_price, ask_qty - trade_qty))
        return trades
