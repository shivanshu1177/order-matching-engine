#!/bin/bash
uvicorn ws_server:app --host 0.0.0.0 --port 8000 &  # Start WebSockets server
streamlit run app.py  # Start Streamlit app
