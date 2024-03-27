function [fraud db] = mu_vote(db, SSN, president)
fraud = false;
db = 0;
ssn = str2num(SSN)
[row col] = size(db);
people_id = [];
for ii = 1:row
    people_id(end+1) = str2num(db{ii,1});
end

for jj = 1:length(people_id)
    if people_id(jj) == ssn
        if isempty(db{jj,2})
            fraud = true;
            db = 1;
        end
    end
end