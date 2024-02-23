def transform(legacy_data):
    return {ll.lower(): key for key, val in legacy_data.items() for ll in val}
