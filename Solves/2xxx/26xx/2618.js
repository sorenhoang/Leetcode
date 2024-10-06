/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    while(obj!=null)
    {
        if(obj.constructor === classFunction)
        {
            return true;
        }

        obj = Object.getPrototypeOf(obj);

    }

    return false;
};


console.log(checkIfInstanceOf(new Date(), Date));
