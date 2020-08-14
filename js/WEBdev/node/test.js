const fs = require('fs')
const path = require('path')
const f1 = path.join(__dirname, 'input.txt')
const f2 = path.join(__dirname, 'input2.txt')
const f3 = path.join(__dirname, 'output.txt')

function readf1() {
    return new Promise((resolve, reject) => {
        fs.readFile(f1,
            // data,
            (err,data) => {
                if (err) throw err
                data = data.toString().split('/n')
                resolve(data)
            })

    })
}

function readf2() {
    return new Promise((resolve, reject) => {
        fs.readFile(f2,
            // data,
            (err,data) => {
                if (err) throw err
                data = data.toString().split('/n')
                resolve(data)
            }
        )

    })
}

function writefileoutput(ans) {
    return new Promise((resolve, reject) => {
        fs.readFile(f3,
            ans,
            (err) => {
                if (err) throw err
                resolve(ans)
            }
        )

    })
}

let ans
readf1()
    .then((data) => {
        ans = data
        return readf2() //this returns Promise of readfilef2
    })
    .then((data) => {
        ans = ans.concat(data)
        ans.sort((a, b) => a - b)
        return writefileoutput(ans)
    })
    .then(() => {
        console.log('All Done!!')
    })