from fastapi import FastAPI

app=FastAPI()

@app.get("/index",tags=["пример"])
def index():
    """пример простого вызова"""
    return "hello world"

@app.get("/messages",tags=["сообшения"])
def messages():
    return{
        "hello":"формируеться приветсвие для кого то",
        "hello":"формируеться прощание для кого то",
    }

@app.get("/messages/hello/{name}",tags=["сообшения"])
def hello(name:str) -> str:
    """формируеться приветсвие для кого то"""
    return f"hello {name}"

@app.get("/messages/bye/{name}",tags=["сообшения"])
def bye(name:str) -> str:
    """формируеться прощание для кого то"""
    return f"godbye {name}"  