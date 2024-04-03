class BufferFullException(BufferError):
    """Exception raised when CircularBuffer is full.

    message: explanation of the error.

    """

    def __init__(self, message):
        self.message = message


class BufferEmptyException(BufferError):
    """Exception raised when CircularBuffer is empty.

    message: explanation of the error.

    """

    def __init__(self, message):
        self.message = message


class CircularBuffer:
    def __init__(self, capacity):
        self.size = capacity
        self.clear()
        self.head = 0
        self.tail = 0

    def read(self):
        data = self.buffer[self.tail]
        if data is None:
            raise BufferEmptyException("Circular buffer is empty")
        self.buffer[self.tail] = None
        self.tail = self.advance_pointer(self.tail)
        return data

    def write(self, data):
        if self.buffer[self.head] is not None:
            raise BufferFullException("Circular buffer is full")
        self.buffer[self.head] = data
        self.head = self.advance_pointer(self.head)

    def overwrite(self, data):
        if self.buffer[self.head] is not None:
            self.tail = self.advance_pointer(self.tail)
        self.buffer[self.head] = data
        self.head = self.advance_pointer(self.head)
        print(self.buffer)

    def clear(self):
        self.buffer = [None] * self.size

    def advance_pointer(self, val):
        return (val + 1) % self.size
