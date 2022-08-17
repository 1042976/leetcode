var RangeModule = function() {
    this.ranges = [];
};

/** 
 * @param {number} val 
 * @return {number}
 */
RangeModule.prototype.upper_bound = function(val){
    let left = 0;
    let right = this.ranges.length;
    while(left < right){
        let mid = Math.floor(left + (right-left)/2);
        if(this.ranges[mid][0] <= val){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
}
/** 
 * @param {number} left 
 * @param {number} right
 * @return {void}
 */
RangeModule.prototype.addRange = function(left, right) {
    let i = this.upper_bound(left);
    let j = this.upper_bound(right);
    if(i > 0 && this.ranges[--i][1] < left){
        ++i;
    }
    if(i < j){
        this.ranges[i] = [Math.min(this.ranges[i][0], left), Math.max(this.ranges[j-1][1], right)];
        this.ranges.splice(i+1, j-i-1);
    }else{
        this.ranges.splice(i, 0, [left, right]);
    }
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {boolean}
 */
RangeModule.prototype.queryRange = function(left, right) {
    let a = this.upper_bound(left)-1;
    return a >= 0 && this.ranges[a][1] >= right; 
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {void}
 */
RangeModule.prototype.removeRange = function(left, right) {
    let i = this.upper_bound(left);
    let j = this.upper_bound(right);
    if(i > 0 && this.ranges[--i][1] < left){
        ++i;
    }
    if(i < j){
        let a = Math.min(this.ranges[i][0], left);
        let b = Math.max(this.ranges[j-1][1], right);
        this.ranges.splice(i, j-i);
        if(a < left){
            this.ranges.splice(i++, 0, [a, left]);
        }
        if(b > right){
            this.ranges.splice(i, 0, [right, b]);
        }
    }
};

/** 
 * Your RangeModule object will be instantiated and called as such:
 * var obj = new RangeModule()
 * obj.addRange(left,right)
 * var param_2 = obj.queryRange(left,right)
 * obj.removeRange(left,right)
 */
