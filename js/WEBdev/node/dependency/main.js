const lib1 = require('./lib1');
const lib2 = require('./lib2');

console.log("main");

// In nodeJs there is dependency graph which helps require thing not to go in cycle
// It form a hashmap dataset i.e when one of the file is require its module.exports = {} is added to hashmap
// and later updated accordingly
// destructuring - {sameName,Samename} iss tareeke se hum direct import kre hue function us kar paayenge jo dusri file k exports mai pde the
// agar hume jaan bhuj k cycle vala kaam krna hai toh module.exports.varName/funcName ese krna padega agar {} mai dala toh hashset ban jata hau
