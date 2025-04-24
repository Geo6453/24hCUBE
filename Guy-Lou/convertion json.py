import json

class Convert_json :

    def convert_json (request : tuple) :

        dict_json = {"type" : request[0], "playload" : request[1]}
        return json.dumps(dict_json)