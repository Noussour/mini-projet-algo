from flask import Flask, request, send_file, jsonify
import pandas as pd
from flask_cors import CORS
import matplotlib.pyplot as plt
import io
import os


app = Flask(__name__)
CORS(app)


@app.route('/upload-csv', methods=['POST'])
def upload_csv():
    if 'file' not in request.files:
        return jsonify({'error': 'No file provided'}), 400

    file = request.files['file']
    if file.filename == '':
        return jsonify({'error': 'No selected file'}), 400

    # Read the CSV file into a DataFrame
    try:
        df = pd.read_csv(file)
    except Exception as e:
        return jsonify({'error': f'Invalid CSV file: {str(e)}'}), 400

    # Check if required columns are present
    if not {'Algorithm', 'Array Size', 'Execution Time'}.issubset(df.columns):
        return jsonify({'error': 'CSV file must contain "Algorithm", "Array Size", and "Execution Time" columns'}), 400

    # Create the plot
    for algo in df["Algorithm"].unique():
        subset = df[df["Algorithm"] == algo]
        plt.plot(subset["Array Size"], subset["Execution Time"], label=algo)

    plt.xlabel("Array Size")
    plt.ylabel("Execution Time (s)")
    plt.title("Sorting Algorithm Performance")
    plt.legend()

    # Save the plot to a BytesIO object
    img = io.BytesIO()
    plt.savefig(img, format='png')
    img.seek(0)
    plt.close()

    # Send the image file back to the frontend
    return send_file(img, mimetype='image/png', as_attachment=True, download_name='plot.png')

if __name__ == '__main__':
    app.run(debug=True)

