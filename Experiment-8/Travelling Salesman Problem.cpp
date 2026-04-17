function dfs(cost, vis, last, cnt) {
    const n = cost.length;

    if (cnt === n)
        return cost[last][0];

    let minCost = 1e9;

    for (let city = 1; city < n; city++) {
        if (!vis[city]) {

            vis[city] = true;
            minCost = Math.min(minCost, cost[last][city] +
                                        dfs(cost, vis, city, cnt + 1));

            vis[city] = false;
        }
    }


    return minCost;
}

function tsp(cost) {
    const n = cost.length;

    const vis = Array(n).fill(false);
    vis[0] = true;

    return dfs(cost, vis, 0, 1);
}

const cost = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
];
const res = tsp(cost);
console.log(res);
