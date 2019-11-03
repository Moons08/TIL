from flask import Flask, render_template, jsonify

app = Flask(__name__)

@app.route("/")
def hello():
    return render_template('profile.html')


if __name__ == "__main__":
    app.run(debug=True)
