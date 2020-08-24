const sqlite = require('sqlite3').verbose();
const db = new sqlite.Database(__dirname + '/test.db');

db.serialize(()=>{
    db.run(
        `CREATE TABLE IF NOT EXISTS tasks(
            id INTEGER AUTO_INCREMENT PRIMARY KEY,
            name TEXT,
            done BOOLEAN
        )`
    )

    db.run(
        `INSERT INTO tasks VALUES(3,'Learn reddis db',false)`
    )

    // db.run(
    //     `DROP TABLE tasks`
    // )
})