const fs = require('fs');
const path = require('path');
const FO = path.join(__dirname,'output.txt');

let ans;

fs.readFile(
    path.join(__dirname,'inp1.txt'),
    (err,data)=>{
        if(err) throw err;
        ans = data.toString().split('\n');

        fs.readFile(
            path.join(__dirname,'inp2.txt'),
            (err,data)=>{
                if(err) throw data;
                let final = ans.concat(data.toString().split('\n'));
                final.sort((a,b)=>a-b);
                final = final.join('\n');
                fs.writeFile(FO,final,(err)=>{
                    if(err) throw err;
                    console.log('done everything!')
                })
            }
        )
    }
)