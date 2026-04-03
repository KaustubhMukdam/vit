from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import requests
response = requests.get('https://fakestoreapi.com/products/1')
print(response.json())

app = FastAPI()

# API Endpoints
# GET Request Methods
@app.get("/")
async def get_request():
    return {"message": "Hello there, this is a GET request"}

# POST Request Methods
@app.post("/")
async def post_request():
    return {"message": "Hello there, this is a POST request"}

# PUT Request Methods
@app.put("/")
async def put_request():
    return {"message":"Hello There, this is a PUT Request"}

# DELETE Request Methods
@app.delete("/")
async def delete_request():
    return {"Hello There, this is a DELETE Request"}

# PATCH Request Methods
@app.patch("/")
async def patch_request():
    return {"Hello There, this is a PATCH Request"}

# Run the server
if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)