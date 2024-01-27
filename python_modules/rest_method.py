from enum import Enum

class RestMethod(Enum):
    def __str__(self):
        return str(self.value)

    POST = 'POST'
    GET = 'GET'
    PUT = 'PUT'
    DELETE = 'DELETE'